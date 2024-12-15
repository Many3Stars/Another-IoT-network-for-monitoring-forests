void sensores_reset(int mode);
void sensores_loop ();
int sensores_data (int mode,char *p);

void fifo1_add(char);
char fifo1_get(void);
int fifo1_empty(void);

void fifo2_add(char);
char fifo2_get(void);
int fifo2_empty(void);

//sensores_ll
void power_on(void);
void power_off(void);
///int adc_read(int channel);