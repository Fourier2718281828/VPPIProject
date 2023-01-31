#include "ConsoleDocumentEditor.h"
#include "Utilities.h"
#include "CommandException.h"
#include <type_traits>

#define ATTACH_METHOD(method_name) \
std::bind(&ConsoleDocumentEditor::method_name, this, std::placeholders::_1)

const char* const ConsoleDocumentEditor::s_APP_BORDER = "###############################################";
const char* const ConsoleDocumentEditor::s_DOC_BORDER = "<--------------------------------------------->";

ConsoleDocumentEditor::ConsoleDocumentEditor
(
	std::ostream& output, 
	std::istream& input
) :
	commands_
	(
		{
			{"?", ATTACH_METHOD(print_help)},
			{"??", ATTACH_METHOD(print_help)},
		}
	),
	output_(output),
	input_(input)
{
	main_loop();
}

auto ConsoleDocumentEditor::print_help(const iterable& params) const -> void
{
	command_params_check(0u, params.size());
	for (auto&& [action, _] : commands_)
	{
		output_ << "# <" << action << '>' << '\n';
	}
}

auto ConsoleDocumentEditor::main_loop() const noexcept -> void
{
	in_text_type in_txt;
	output_ << s_APP_BORDER;
	output_ << "Welcome to our Document Editor\n";
	output_ << "What you can do [<command>]:\n";
	print_help({});
	output_ << "Awaiting your command...\n";
	do
	{
		output_ << '>';
		std::getline(input_, in_txt);
		auto [first, params] = parse_user_command(in_txt);
		try
		{
			commands_.at(first).operator()(params);
		}
		catch (const CommandException& ex)
		{
			output_ << ex.what() << '\n';
		}
		catch (const std::out_of_range&)
		{
			output_ << "***No such a command.\n";
		}
	} while (true);
	output_ << "Have a nice day!\n";
	output_ << s_APP_BORDER;
}

auto ConsoleDocumentEditor::parse_user_command(const in_text_type& input) 
const noexcept -> const std::pair<in_text_type, iterable>
{
	auto delims = " ";
	auto tokens = tokenize(input, in_text_type(delims));
	auto itor = tokens.begin();
	auto etor = tokens.end();
	auto first = *itor++;
	return { first, {itor, etor} };
}

auto ConsoleDocumentEditor::command_params_check
(
	const unsigned short needed_num_of_args, 
	const unsigned short actual_num_of_args
) const -> void
{
	if (needed_num_of_args != actual_num_of_args)
		throw CommandException("***Invalid number of params");
}
