#include "TextHeader.h"
#include <iostream>

void insert_text(const IDocument&, const IHeader::text_type&)
{
	std::cout << "insert_text called" << '\n';
}

void remove_last_word(const IDocument&) noexcept
{
	std::cout << "remove_last_word called" << '\n';
}

void clear_document(const IDocument&) noexcept
{
	std::cout << "clear_document called" << '\n';
}

const TextHeader::input_ops_container_type TextHeader::s_INPUT_OPERATIONS =
{
	{"Insert text", static_cast<TextHeader::input_operation_type>(insert_text)},
};

const TextHeader::procedures_container_type TextHeader::s_PROCEDURES =
{
	{"Remove last word", static_cast<IHeader::procedure_type>(remove_last_word)},
	{"Clear document", static_cast<IHeader::procedure_type>(clear_document)},
};

auto TextHeader::get_title() const noexcept -> const caption_txt_type
{
	return "Text Document Editor:";
}

auto TextHeader::get_input_operations() const noexcept -> const input_ops_container_type&
{
	return s_INPUT_OPERATIONS;
}

auto TextHeader::get_procedures() const noexcept -> const procedures_container_type&
{
	return s_PROCEDURES;
}
