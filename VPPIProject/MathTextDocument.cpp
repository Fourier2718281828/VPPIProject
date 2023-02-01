#include "MathTextDocument.h"
#include <algorithm>
#include "BadDocumentException.h"

auto MathTextDocument::get_text() const noexcept -> const text_type&
{
    return text_;
}

auto MathTextDocument::append_text(const text_type& txt) -> void
{
    if (!check_for_correctness(txt))
        throw BadDocumentException("Unacceptable text for math document");
    text_.append(txt);
}

auto MathTextDocument::clear() noexcept -> void
{
    text_.clear();
}

auto MathTextDocument::check_for_correctness(const text_type& txt) const noexcept -> bool
{
    //some math logic...
    return true;
}
