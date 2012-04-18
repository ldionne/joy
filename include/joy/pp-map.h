/*!
 * This file defines an interface to a generic map (dict) data structure.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PP_MAP_H
#define NSTL_PP_MAP_H

#include "pp-tree.h"
#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/replace.h>


#define NSTL_PP_MAP(key_comp) (key_comp, NSTL_PP_TREE())

#define NSTL_PP_MAP_KEY_COMP(map) CHAOS_PP_TUPLE_ELEM(2, 0, map)
#define NSTL_PP_MAP_IMPL_TREE_(map) CHAOS_PP_TUPLE_ELEM(2, 1, map)

#define NSTL_PP_MAP_CELL_(key, value) (key, value)
#define NSTL_PP_MAP_CELL_KEY_(cell) CHAOS_PP_TUPLE_ELEM(2, 0, cell)
#define NSTL_PP_MAP_CELL_VALUE_(cell) CHAOS_PP_TUPLE_ELEM(2, 1, cell)

#define NSTL_PP_MAP_SET_IMPL_TREE_(map, tree) \
    CHAOS_PP_TUPLE_REPLACE(1, map, tree)
/**/

#define NSTL_PP_MAP_EMPTY(map) NSTL_PP_TREE_EMPTY(NSTL_PP_MAP_IMPL_TREE_(map))

#define NSTL_PP_MAP_SIZE(map) NSTL_PP_TREE_SIZE(NSTL_PP_MAP_IMPL_TREE_(map))

#define NSTL_PP_MAP_CLEAR(map) NSTL_PP_MAP_SET_IMPL_TREE_( \
    NSTL_PP_TREE_CLEAR(NSTL_PP_MAP_IMPL_TREE_(map)))
/**/

#define NSTL_PP_MAP_FIND(map, key, default) NSTL_PP_MAP_CELL_VALUE_( \
    NSTL_PP_TREE_FIND(NSTL_PP_MAP_IMPL_TREE_(map), \
        NSTL_PP_MAP_CELL_(key, ~), NSTL_PP_MAP_KEY_COMP(map), default))
/**/

#define NSTL_PP_MAP_CONTAINS(map, key) NSTL_PP_TREE_CONTAINS( \
    NSTL_PP_MAP_IMPL_TREE_(map), NSTL_PP_MAP_CELL_(key, ~), NSTL_PP_MAP_KEY_COMP(map))
/**/

#define NSTL_PP_MAP_ADD(map, key, value) NSTL_PP_MAP_SET_IMPL_TREE_(map, \
    NSTL_PP_TREE_INSERT(NSTL_PP_MAP_IMPL_TREE_(map), \
                    NSTL_PP_MAP_CELL_(key, value), NSTL_PP_MAP_KEY_COMP(map)))
/**/

#define NSTL_PP_MAP_REMOVE(map, key) NSTL_PP_MAP_SET_IMPL_TREE_(map, \
    NSTL_PP_TREE_REMOVE(NSTL_PP_MAP_IMPL_TREE_(map), NSTL_PP_MAP_CELL_(key, ~), \
                                                    NSTL_PP_MAP_KEY_COMP(map)))
// would be cool if the tree could set a flag if found/not found
#define NSTL_PP_MAP_REMOVE_INEXISTANT_KEY_REMOVED_EXCEPTION()
/**/

#endif /* !NSTL_PP_MAP_H */
