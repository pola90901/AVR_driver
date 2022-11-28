#ifndef util_h
#define util_h
#define set_bit(var,bitpos)    (var=var |(1<<bitpos))
#define clear_bit(var,bitpos)  (var =var &~(1<<bitpos))
#define toggle_bit(var,bitpos) (var=var ^ (1<<bitpos))
#define Get_bit(var,bitpos)   ((1&(var>>bitpos)))
#define Assign_Bit(Var,Bit_No,Value) do{if(Value == 1) set_bit(Var,Bit_No); \
										else clear_bit(Var,Bit_No);}while(0)

#endif
