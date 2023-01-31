#ifndef CONSOLE_DOC_EDITOR_
#define CONSOLE_DOC_EDITOR_
#include "Application.h"
#include "IHeader.h"
#include "IDocument.h"
#include "IFactories.h"
#include <memory>
#include <iostream>
#include <map>
#include <functional>
#include <utility>
#include <concepts>

class ConsoleDocumentEditor : public Application
{
private:
	template<typename T>
	using ptr = std::shared_ptr<T>;
	using factory_type = IDocHeaderFactory;
	using in_text_type = std::string;
	using iterable = std::vector<in_text_type>;
	using command = std::function<void(const iterable&)>;
	using command_map = std::map<in_text_type, command>;
public:
	ConsoleDocumentEditor(std::ostream&, std::istream&);
	~ConsoleDocumentEditor() override = default;
	int execute() const noexcept override;
public:
	template<typename FactoryType>
		requires std::is_default_constructible_v<FactoryType>
	static bool register_factory(const DocumentType);
public:
	ConsoleDocumentEditor(const ConsoleDocumentEditor&) = delete;
	ConsoleDocumentEditor& operator=(const ConsoleDocumentEditor&) = delete;
public:
	void print_help(const iterable&) const;
	void new_document(const iterable&) const;
	void open_document(const iterable&) const;
	void close_document(const iterable&) const;
private:
	void main_loop() const noexcept;
	const std::pair<in_text_type, iterable> parse_user_command(const in_text_type&) const noexcept;
	void command_params_check(const unsigned short, const unsigned short) const;
	//void show_document()
	static in_text_type doctype_to_string(const DocumentType);
private:
	const command_map commands_;
	std::ostream& output_;
	std::istream& input_;
	ptr<IHeader> current_header_;
	ptr<IDocument> current_document_;
	ptr<factory_type> doc_creator_;
private:
	static const char* const s_APP_BORDER;
	static const char* const s_DOC_BORDER;
	static const char* const s_DEFAULT_FILENAME;
	static std::map<in_text_type, ptr<factory_type>> s_DOCUMENT_TYPES_TO_FACTORIES;
};

template<typename FactoryType>
	requires std::is_default_constructible_v<FactoryType>
inline static bool ConsoleDocumentEditor::register_factory(const DocumentType doc_type)
{
	auto param_name = doctype_to_string(doc_type);
	auto factory_ptr = std::make_shared<FactoryType>();
	auto [_, result] = s_DOCUMENT_TYPES_TO_FACTORIES.insert({ param_name , factory_ptr });
	return result;
}

#endif // !CONSOLE_DOC_EDITOR_
