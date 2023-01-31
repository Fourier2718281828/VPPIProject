#ifndef APPLICATION_
#define APPLICATION_
#include "IHeader.h"
#include "IDocument.h"
#include <memory>
#include <iostream>
#include <map>
#include <functional>
#include <utility>

class ConsoleDocumentEditor
{
private:
	using in_text_type = std::string;
	using iterable = std::vector<in_text_type>;
	using command = std::function<void(const iterable&)>;
	using command_map = std::map<in_text_type, command>;
	template<typename T>
	using ptr = std::shared_ptr<T>;
public:
	ConsoleDocumentEditor(std::ostream&, std::istream&);
	~ConsoleDocumentEditor() = default;
public:
	ConsoleDocumentEditor(const ConsoleDocumentEditor&) = delete;
	ConsoleDocumentEditor& operator=(const ConsoleDocumentEditor&) = delete;
public:
	void print_help(const iterable&) const;
	void command2(const iterable&) const;
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
	ptr<IHeader> header_;
	ptr<IDocument> current_document_;
private:
	static const char* const s_APP_BORDER;
	static const char* const s_DOC_BORDER;
};

#endif // !APPLICATION_

