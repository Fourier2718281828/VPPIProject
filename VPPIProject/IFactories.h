#ifndef TEXT_EDITOR_FACTORY
#define TEXT_EDITOR_FACTORY
#include "loki/AbstractFactory.h"
#include "loki/Typelist.h"
#include "loki/HierarchyGenerators.h"
#include "IDocument.h"
#include "IHeader.h"
#include <memory>


template<typename T>
struct Dispatcher {};

template<typename AbstractProduct>
class IFactoryUnit
{
public:
	using abstract_product_ptr = std::unique_ptr<AbstractProduct>;
public:
	virtual ~IFactoryUnit() = default;
private:
	virtual abstract_product_ptr Create(Dispatcher<AbstractProduct>) const = 0;
};

template
<
	template<typename> typename Unit,
	typename AbstractProductTypes
>
class IFactory : public Loki::GenScatterHierarchy<AbstractProductTypes, Unit>
{
public:
	template<typename T>
	using abstract_product_ptr = Unit<T>::abstract_product_ptr;
public:
	~IFactory() override = default;
public:
	template<typename AbstractProduct>
	abstract_product_ptr<AbstractProduct> Create() const
	{
		Unit<AbstractProduct>& unit = *this;
		return unit.Create(Dispatcher<AbstractProduct>{});
	}
};

using IDocHeaderFactory = IFactory<IFactoryUnit, LOKI_TYPELIST_2(IDocument, IHeader)>;

#endif // !TEXT_EDITOR_FACTORY
