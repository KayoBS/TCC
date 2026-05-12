#ifndef ACS712
#define ACS712

class Acs712 {
  private:
    unsigned short out_pin;

  public:
    Acs712(unsigned short out_pin);
    float getCurrent();

};

#endif
