#ifndef MATH_TEXT_DOCUMENT_
#define MATH_TEXT_DOCUMENT_
#include "IDocument.h"

class MathTextDocument : public IDocument
{
public:
	const text_type& get_text() const noexcept override;
	void append_text(const text_type&) override;
	void clear() noexcept override;
private:
	bool check_for_correctness(const text_type&) const noexcept;
private:
	text_type text_;
};

#endif // !MATH_TEXT_DOCUMENT_
