#ifndef util_h
#define util_h
#define set_bit(var,bitpos) var=var |(1<<bitpos)
#define clear_bit(var,bitpos) var =var &~(1<<bitpos)
#define toggle_bit(var,bitpos) var=var ^ (1<<bitpos)
#endif
