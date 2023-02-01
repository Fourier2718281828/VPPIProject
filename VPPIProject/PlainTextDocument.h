#ifndef PLAIN_TEXT_DOCUMENT_
#define PLAIN_TEXT_DOCUMENT_
#include "IDocument.h"

class PlainTextDocument : public IDocument
{
public:
	const text_type& get_text() const noexcept override;
	void append_text(const text_type&) override;
	void clear() noexcept override;
public:
	void serialize(std::ofstream&) const override;
	ptr<ISerializable> deserialize(std::ifstream&) override;
private:
	text_type text_;
private:
	static constexpr const DocumentType s_TYPE = DocumentType::MATH_TEXT;
};

#endif // !PLAIN_TEXT_DOCUMENT_
