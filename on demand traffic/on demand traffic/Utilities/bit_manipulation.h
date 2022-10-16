/*
 * bit_manipulation.h
 *
 * Created: 4/9/2022 3:45:50 PM
 *  Author: ameln
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_
//bit operations

//clear the bit
#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM)
//write a value to bit
#define SET_BIT(REG,NUM) REG|=(1<<NUM)
//toggle bit value(statues)
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM)
//read the bit value
#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM)

#endif /* BIT_MANIPULATION_H_ */