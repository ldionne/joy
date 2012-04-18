/*!
 * This file defines an interface to create and manipulate metatypes.
 *
 * @author Louis Dionne
 */

#include "pp-map.h"
#include <chaos/preprocessor/logical/not.h>
#include <chaos/preprocessor/detection/compare.h>
#include <chaos/preprocessor/detection/is_empty.h>


/*!
 * Define a new metatype.
 *
 * To define a new metatype, one must register it to the library :
 *
 * @code
 * #define NSTL_TYPE_NameOfTheNewMetaType \
 *      NSTL_TYPE(NameOfTheUnderlyingCType, Traits)
 * @endcode
 * 
 * After this step, NameOfTheNewMetaType can be used in library macros
 * whenever a registered metatype is expected.
 *
 * A property of metatypes is that they can be parametrized. Since they are
 * really just macros in the end, it is perfectly possible to do the following :
 *
 * @code
 * #define NSTL_TYPE_TemplatedMetaType(typename_T) \
 *      NSTL_TYPE(NameOfTheUnderlyingCType, Traits)
 * @endcode
 *
 * Where this becomes very interesting is when combined with a parametrized
 * implementation :
 *
 * @code
 * // SomeHeader.h
 *
 * #define TemplatedType(typename_T) \
 *      CHAOS_PP_CAT(SomePrefixToAvoidCollisions_, typename_T)
 *
 * #define NSTL_TYPE_TemplatedType(typename_T) \
 *      NSTL_TYPE(TemplatedType(typename_T), Traits)
 *
 * #define INSTANTIATE_TemplatedType(typename_T) \
 *      typedef struct { \
 *          int some_member_irrelevant_to_the_example; \
 *      } TemplatedType(typename_T);
 *
 *
 * // SomeClientFile.c
 *
 * #include <SomeHeader.h>
 * INSTANTIATE_TemplatedType(int)
 * INSTANTIATE_TemplatedType(char)
 *
 * TemplatedType(int) foo;
 * TemplatedType(char) bar;
 * @endcode
 *
 * @param Ctype The underlying C type of the metatype.
 * @param traits A (possibly empty) tuple of traits giving metainformation
 *              about the metatype.
 */
#define NSTL_TYPE(Ctype, traits) \
    NSTL_PP_MAP_ADD(NSTL_PP_MAP_ADD(NSTL_PP_MAP(NSTL_TYPE_IMPL_MAP_LESS_), \
        NSTL_IMPL_TYPE_Ctype, Ctype), NSTL_IMPL_TYPE_traits, traits)

#define CHAOS_PP_COMPARE_NSTL_IMPL_TYPE_Ctype(x) x
#define CHAOS_PP_COMPARE_NSTL_IMPL_TYPE_traits(x) x
// temporary hack until map is ready
#define NSTL_TYPE_IMPL_MAP_LESS_(a, b) NSTL_TYPE_IMPL_MAP_LESS_I_( \
    NSTL_PP_MAP_CELL_KEY_(a), NSTL_PP_MAP_CELL_KEY_(b))
#define NSTL_TYPE_IMPL_MAP_LESS_I_(a, b) CHAOS_PP_NOT(CHAOS_PP_COMPARE(a, b))
/**/

/*!
 * Retrieve the metainformation of a metatype.
 *
 * @note NSTL_TYPE_INFO() should not be used inside other macros because the
 *          metatype parameter would be expanded, which is not desirable in
 *          most cases. For example, templated metatypes using the technique
 *          presented above would expand to an invalid C type name instead of
 *          the metatype's name to be CHAOS_PP_CAT'd with NSTL_TYPE_.
 */
#define NSTL_TYPE_INFO(metatype) NSTL_TYPE_ ## metatype

/*!
 * Retrieve the underlying C type of a metatype.
 */
#define NSTL_TYPE_CTYPE(metatype) \
    NSTL_PP_MAP_FIND(NSTL_TYPE_ ## metatype, NSTL_IMPL_TYPE_Ctype, Invalid)

/*!
 * Retrieve the traits of a metatype.
 */
#define NSTL_TYPE_TRAITS(metatype) \
    NSTL_PP_MAP_FIND(NSTL_TYPE_ ## metatype, NSTL_IMPL_TYPE_traits, Invalid)



















#if 0

#define small_tree \
	NSTL_PP_BNODE(NSTL_PP_BNODE_LEAF(1), 2, NSTL_PP_BNODE_LEAF(3))
/*
   2
 /  \
1    3
*/

#define b_leaf NSTL_PP_BNODE_LCHILD(small_tree)
#define c_leaf NSTL_PP_BNODE_RCHILD(small_tree)
#define less(a, b) CHAOS_PP_LESS(a, b)


~~small tree~~
assert 0 == NSTL_PP_BNODE_IS_LEAF(small_tree)
assert 2 == NSTL_PP_BNODE_DATA(small_tree)

~~b leaf~~
assert 1 == NSTL_PP_BNODE_IS_LEAF(b_leaf)
assert 1 == NSTL_PP_BNODE_DATA(b_leaf)

~~c leaf~~
assert 1 == NSTL_PP_BNODE_IS_LEAF(c_leaf)
assert 3 == NSTL_PP_BNODE_DATA(c_leaf)

~~~~~
assert 3 == NSTL_PP_TREE_FIND(small_tree, 3, less, nil)
assert nil == NSTL_PP_TREE_FIND(small_tree, 4, less, nil)

assert 1 == NSTL_PP_TREE_CONTAINS(small_tree, 3, less)
assert 0 == NSTL_PP_TREE_CONTAINS(small_tree, 4, less)

assert 3 == NSTL_PP_TREE_SIZE(small_tree)

NSTL_PP_TREE_INSERT(small_tree, 5, less)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define small_set NSTL_PP_SET(less)

small_set


#define set_with_1 NSTL_PP_SET_ADD(small_set, 1)

NSTL_PP_SET_FIND(set_with_1, 1, problem)
NSTL_PP_SET_CONTAINS(set_with_1, 1)

/*************************
changements a faire :
1)
finir d'implementer map

2)
utiliser une vraie recursion
***************************/

~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//kind of recursion. look into it later. don't forget to increment s though.

#define NSTL_PP_BNODE_VISIT(s, node, visit) \
CHAOS_PP_CAT(NSTL_PP_BNODE_VISIT_, s)(node, visit)

#define NSTL_PP_BNODE_VISIT_0(s, node, visit) CHAOS_PP_BRANCH \
(0xIF) (NSTL_PP_BNODE_IS_NULL(node)) ( \
node \
) (0xELSE) ( \
visit(s, node) \
) (0xENDIF)

#define visit(s, node) \
    NSTL_PP_BNODE( \
        NSTL_PP_BNODE_VISIT(s, NSTL_PP_BNODE_LCHILD(node)), \
            NSTL_PP_BNODE_DATA(node), \
        NSTL_PP_BNODE_VISIT(s, NSTL_PP_BNODE_RCHILD(node)) \
    )

#endif // 0
