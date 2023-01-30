#ifndef TEXT_HEADER_
#define TEXT_HEADER_
#include "IHeader.h"

class TextHeader : public IHeader
{
public:
	TextHeader() = default;
	~TextHeader() override = default;
public:
	const caption_txt_type get_title() const noexcept override;
	const input_ops_container_type& get_input_operations() const noexcept override;
	const procedures_container_type& get_procedures() const noexcept override;
private:
	static const input_ops_container_type s_INPUT_OPERATIONS;
	static const procedures_container_type s_PROCEDURES;
};

#endif // !TEXT_HEADER_
