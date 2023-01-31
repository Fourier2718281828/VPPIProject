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

class ConsoleDocumentEditor : public Application
{
private:
	using factory_type = IDocHeaderFactory;
	using in_text_type = std::string;
	using iterable = std::vector<in_text_type>;
	using command = std::function<void(const iterable&)>;
	using command_map = std::map<in_text_type, command>;
	template<typename T>
	using ptr = std::shared_ptr<T>;
public:
	ConsoleDocumentEditor(std::ostream&, std::istream&);
	~ConsoleDocumentEditor() override = default;
	int execute() const noexcept override;
public:
	ConsoleDocumentEditor(const ConsoleDocumentEditor&) = delete;
	ConsoleDocumentEditor& operator=(const ConsoleDocumentEditor&) = delete;
public:
	void print_help(const iterable&) const;
	void new_document(const iterable&) const;
	void command3(const iterable&) const;
	void command4(const iterable&) const;
private:
	void main_loop() const noexcept;
	const std::pair<in_text_type, iterable> parse_user_command(const in_text_type&) const noexcept;
	void command_params_check(const unsigned short, const unsigned short) const;
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

#endif // !CONSOLE_DOC_EDITOR_

