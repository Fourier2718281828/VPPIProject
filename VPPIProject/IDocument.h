#ifndef IDOCUMENT_
#define IDOCUMENT_
#include <string>

enum class DocumentType
{
	PLAIN_TEXT,
	MATH_TEXT,
};

class IDocument
{
public:
	using text_type = std::string;
public:
	virtual ~IDocument() = default;
public:
	virtual const text_type& get_text() const noexcept = 0;
	virtual void append_text(const text_type&) = 0;
	virtual void clear() noexcept = 0;
};

#endif // !IDOCUMENT_
