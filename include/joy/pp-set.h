/*!
 * This file defines an interface to manipulate a generic set container.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PP_SET_H
#define NSTL_PP_SET_H

#include "pp-tree.h"
#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/replace.h>


#define NSTL_PP_SET(value_comp) (value_comp, NSTL_PP_TREE())

#define NSTL_PP_SET_VALUE_COMP(set) CHAOS_PP_TUPLE_ELEM(2, 0, set)
#define NSTL_PP_SET_IMPL_TREE_(set) CHAOS_PP_TUPLE_ELEM(2, 1, set)

#define NSTL_PP_SET_SET_IMPL_TREE_(set, tree) \
    CHAOS_PP_TUPLE_REPLACE(1, set, tree)
/**/

#define NSTL_PP_SET_EMPTY(set) NSTL_PP_TREE_EMPTY(NSTL_PP_SET_IMPL_TREE_(set))

#define NSTL_PP_SET_SIZE(set) NSTL_PP_TREE_SIZE(NSTL_PP_SET_IMPL_TREE_(set))

#define NSTL_PP_SET_CLEAR(set) NSTL_PP_SET_SET_IMPL_TREE_( \
    NSTL_PP_TREE_CLEAR(NSTL_PP_SET_IMPL_TREE_(set)))
/**/

#define NSTL_PP_SET_FIND(set, value, default) NSTL_PP_TREE_FIND( \
    NSTL_PP_SET_IMPL_TREE_(set), value, NSTL_PP_SET_VALUE_COMP(set), default)
/**/

#define NSTL_PP_SET_CONTAINS(set, value) NSTL_PP_TREE_CONTAINS( \
    NSTL_PP_SET_IMPL_TREE_(set), value, NSTL_PP_SET_VALUE_COMP(set))
/**/

#define NSTL_PP_SET_ADD(set, value) NSTL_PP_SET_SET_IMPL_TREE_(set, \
    NSTL_PP_TREE_INSERT(NSTL_PP_SET_IMPL_TREE_(set), value, \
                                                NSTL_PP_SET_VALUE_COMP(set)))
/**/

#define NSTL_PP_SET_REMOVE(set, value) NSTL_PP_SET_SET_IMPL_TREE_(set, \
    NSTL_PP_TREE_REMOVE(NSTL_PP_SET_IMPL_TREE_(set), value, \
                                                NSTL_PP_SET_VALUE_COMP(set)))
// would be cool if the tree could set a flag if found/not found
#define NSTL_PP_SET_REMOVE_INEXISTANT_VALUE_REMOVED_EXCEPTION()
/**/

#define NSTL_PP_SET_DISCARD(set, value) \
    pass
/**/

#endif /* !NSTL_PP_SET_H */
