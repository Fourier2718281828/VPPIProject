#include "PlainTextDocument.h"

auto PlainTextDocument::get_text() const noexcept -> const text_type&
{
    return text_;
}

auto PlainTextDocument::append_text(const text_type& txt) -> void
{
    text_ += txt;
}

auto PlainTextDocument::clear() noexcept -> void
{
    text_.clear();
}
