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
    os.write(reinterpret_cast<const char*>(&s_TYPE), sizeof s_TYPE);
    os.write(text_.c_str(), text_.size());
}

auto MathTextDocument::deserialize(std::ifstream& is) -> void
{
    text_.clear();
    is.read(text_.data(), text_.size());
}

auto MathTextDocument::check_for_correctness(const text_type& txt) const noexcept -> bool
{
    //some math logic...
    return true;
}

auto create_document_math() noexcept -> ISerializer::ptr<ISerializable>
{
    return std::make_unique<MathTextDocument>();
}

auto MathTextDocument::register_for_serialization(DocumentSerializer& ser) -> void
{
    ser.register_product(s_TYPE, &create_document_math);
}