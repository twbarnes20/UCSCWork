#ifndef __ATTRS_H__
#define __ATTRS_H__

enum Attrs    {ATTR_void, ATTR_int, ATTR_null, ATTR_string,
	      ATTR_struct, ATTR_array, ATTR_function, ATTR_variable,
	      ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
	      ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
  };

struct location {
   size_t filenr;
   size_t linenr;
   size_t offset;
   size_t blocknr;
};

#endif 
