#pragma once
#include "ISerializer.h"
#include "DeserializeException.h"
#include "IDocument.h"
#include <map>
#include <functional>

template
<
	typename IdentifierType, 
	typename ProductCreator = std::function<ISerializer::ptr<ISerializable>(void)>
>
class ConcreteSerializer : public ISerializer
{
private:
	using AssocMap = std::map<IdentifierType, ProductCreator>;

public:

	bool register_product(const IdentifierType& id, ProductCreator creator)
	{
		return associations_.insert(AssocMap::value_type(id, creator)).second;
	}

	bool unregister_product(const IdentifierType& id) const
	{
		return associations_.erase(id) == 1;
	}

	void serialize(std::ofstream& of, const ISerializable& product) const override
	{
		product.serialize(of);
	}

	ptr<ISerializable> deserialize(std::ifstream& fs) override
	{
		IdentifierType id;
		fs.read(reinterpret_cast<char*>(&id), sizeof IdentifierType);

		auto i = associations_.find(id);

		if (i != associations_.end())
		{
			return (i->second)();
		}

		throw DecerializeException("Unknown Type");
	}

private:
	AssocMap associations_;
};

using DocumentSerializer = ConcreteSerializer<IDocument::Type>;