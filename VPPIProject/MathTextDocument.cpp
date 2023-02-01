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

auto MathTextDocument::serialize(std::ofstream& os) const -> void
{
    const auto size = text_.size();
    os.write(reinterpret_cast<const char*>(&s_TYPE), sizeof s_TYPE);
    os.write(reinterpret_cast<const char*>(&size), sizeof size);
    os.write(text_.c_str(), text_.size());
}

auto MathTextDocument::deserialize(std::ifstream& is) -> void
{
    size_t size;
    is.read(reinterpret_cast<char*>(&size), sizeof size_t);
    text_.clear();
    is.read(text_.data(), size);
}

auto MathTextDocument::type() const noexcept -> Type
{
    return s_TYPE;
}

auto MathTextDocument::check_for_correctness(const text_type& txt) const noexcept -> bool
{
    //some math logic...
    return true;
}

auto create_document_math(std::ifstream& is) noexcept -> ISerializer::ptr<ISerializable>
{
    auto ptr = std::make_unique<MathTextDocument>();
    ptr->deserialize(is);
    return ptr;
}

auto MathTextDocument::register_for_serialization(DocumentSerializer& ser) -> void
{
    ser.register_product(s_TYPE, &create_document_math);
}