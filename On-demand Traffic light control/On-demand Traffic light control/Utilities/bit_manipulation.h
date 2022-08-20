/*
 * bit_manipulation.h
 *
 * Created: 8/12/2022 6:47:40 PM
 *  Author: fahds
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_



#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM)
#define SET_BIT(REG,NUM) REG|=(1<<NUM)
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM)
#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM)

#endif /* BIT_MANIPULATION_H_ */