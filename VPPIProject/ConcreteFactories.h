#ifndef CONCRETE_FACTORIES_
#define CONCRETE_FACTORIES_
#include "IFactories.h"
#include "loki/TypeManip.h"
#include "loki/Sequence.h"
#include "PlainTextDocument.h"
#include "MathTextDocument.h"
#include "TextHeader.h"

template <class ConcreteProduct, class Base>
class ConcreteFactoryUnit : public Base
{
private:
	using BaseProductList = typename Base::ProductList;
protected:
	using ProductList = typename BaseProductList::Tail;
public:
	using AbstractProduct = typename BaseProductList::Head;
public:
	typename Base::abstract_product_ptr Create(Dispatcher<AbstractProduct>)
	{
		return std::make_unique<ConcreteProduct>();
	}
};

template
<
	typename AbstractFact,
	typename ProductTypes,// = typename AbstractFact::ProductList
	template <typename, typename> typename Unit = ConcreteFactoryUnit
>
class ConcreteFactory : 
	public Loki::GenLinearHierarchy 
	<
		typename Loki::TL::Reverse<ProductTypes>::Result,
		Unit,
		AbstractFact
	>
{
public:
	using ProductList = typename AbstractFact::ProductList;
	using ConcreteProductList = ProductTypes;
};

using PlainTextFactory = ConcreteFactory
<
	IDocHeaderFactory,
	LOKI_TYPELIST_2(PlainTextDocument, TextHeader),
	ConcreteFactoryUnit
>;

using MathTextFactory = ConcreteFactory
<
	IDocHeaderFactory,
	LOKI_TYPELIST_2(MathTextDocument, TextHeader), //TODO ADD MATH TEXT HEADER!!!
	ConcreteFactoryUnit
>;

#endif // !CONCRETE_FACTORIES_
