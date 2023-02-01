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

auto PlainTextDocument::serialize(std::ofstream& os) const -> void
{
    os.write(reinterpret_cast<const char*>(&s_TYPE), sizeof s_TYPE);
    os.write(text_.c_str(), text_.size());
}

auto PlainTextDocument::deserialize(std::ifstream& is) -> ptr<ISerializable>
{
    text_.clear();
    is.read(text_.data(), text_.size());
}