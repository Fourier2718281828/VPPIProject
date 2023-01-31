#ifndef IHEADER_
#define IHEADER_
#include <string>
#include <map>
#include <utility>
#include <functional>
#include "IDocument.h"

class IHeader
{
public:
	using text_type = IDocument::text_type;
	using caption_txt_type = std::string;
	using input_operation_type = 
		std::function<void(const IDocument&, const text_type&)>;
	using procedure_type = std::function<void(const IDocument&)>;
	using input_ops_container_type = std::map<caption_txt_type, input_operation_type>;
	using procedures_container_type = std::map<caption_txt_type, procedure_type>;
public:
	virtual ~IHeader() = default;
public:
	virtual const caption_txt_type get_title() const noexcept = 0;
	virtual const input_ops_container_type& get_input_operations() const noexcept = 0;
	virtual const procedures_container_type& get_procedures() const noexcept = 0;
};

#endif // !IHEADER_

