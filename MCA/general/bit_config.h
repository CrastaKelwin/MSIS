#ifndef _BIT_CONFIG_H_
#define _BIT_CONFIG_H_

#define SET_REG_BIT(REG,bit) (REG|=(0x01U<<bit))
#define CLR_REG_BIT(REG,bit) (REG&=~(0x01U<<bit))

#define SET_REG_BITS(REG,from,to) (REG|=(0xffffffffU<<from)>>(31-to))
#define CLR_REG_BITS(REG,from,to) (REG&=~(0xffffffffU<<from)>>(31-to))

#endif // _BIT_CONFIG_H_
