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
    const auto size = text_.size();
    os.write(reinterpret_cast<const char*>(&s_TYPE), sizeof s_TYPE);
    os.write(reinterpret_cast<const char*>(&size), sizeof size);
    os.write(text_.c_str(), text_.size());
}

auto PlainTextDocument::deserialize(std::ifstream& is) -> void
{
    size_t size;
    is.read(reinterpret_cast<char*>(&size), sizeof size_t);
    text_.clear();
    is.read(text_.data(), size);
}

auto PlainTextDocument::type() const noexcept -> Type
{
    return s_TYPE;
}

auto create_document(std::ifstream& is) noexcept -> ISerializer::ptr<ISerializable>
{
    auto ptr = std::make_unique<PlainTextDocument>();
    ptr->deserialize(is);
    return ptr;
}

auto PlainTextDocument::register_for_serialization(DocumentSerializer& ser) -> void
{
    ser.register_product(s_TYPE, &create_document);
}
