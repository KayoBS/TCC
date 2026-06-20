#ifndef ACS712
#define ACS712

class acs712 {
private:
  byte pin;
  acs712() {}

public:
  acs712( byte pin );

  float getvolts();
  float getamps();

};

#endif
