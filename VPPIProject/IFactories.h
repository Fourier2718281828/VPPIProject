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
	using ProductList = AbstractProductTypes;
public:
	~IFactory() override = default;
public:
	template<typename AbstractProduct>
	abstract_product_ptr<AbstractProduct> Create() const
	{
		Unit<AbstractProduct>& unit = *this;
		return unit.DoCreate(Dispatcher<AbstractProduct>{});
	}
};

using IDocHeaderFactory = IFactory<IFactoryUnit, LOKI_TYPELIST_2(IDocument, IHeader)>;













//template <class AbstractProduct>
//class MyAbstractFactoryUnit
//{
//public:
//	virtual ~MyAbstractFactoryUnit() = default;
//private:
//	virtual AbstractProduct* DoCreate(Loki::Type2Type<AbstractProduct>) const = 0;
//};

//// interface of generalized abstract factory
//template
//<
//	class TList,
//	template <class> class Unit = MyAbstractFactoryUnit
//>
//class MyAbstractFactory : public GenScatterHierarchy<TList, Unit>
//{
//public:
//	using ProductList = TList;
//	template <class T> T* Create()
//	{
//		Unit<T>& unit = *this;
//		return unit.DoCreate(Type2Type<T>());
//	}
//};

#endif // !TEXT_EDITOR_FACTORY
