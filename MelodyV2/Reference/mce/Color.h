
class mce::Color { /* Size=0x10 */
  /* 0x0000 */ float r;
  /* 0x0004 */ float g;
  /* 0x0008 */ float b;
  /* 0x000c */ float a;
  static const mce::Color WHITE;
  static const mce::Color GREY;
  static const mce::Color BLACK;
  static const mce::Color RED;
  static const mce::Color GREEN;
  static const mce::Color BLUE;
  static const mce::Color YELLOW;
  static const mce::Color ORANGE;
  static const mce::Color PURPLE;
  static const mce::Color CYAN;
  static const mce::Color PINK;
  static const mce::Color NIL;
  static const mce::Color SHADE_DOWN;
  static const mce::Color SHADE_UP;
  static const mce::Color SHADE_NORTH_SOUTH;
  static const mce::Color SHADE_WEST_EAST;
  static const mce::Color MINECOIN_GOLD;
  
  Color(const mce::Color&, float);
  Color(float, float, float, float);
  Color();
  void initialize(const mce::Color&);
  void add(float, bool);
  void mul(float, bool);
  const float* data() const;
  bool isNormalized() const;
  int32_t toARGB() const;
  int32_t toABGR() const;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > toHexString() const;
  float average() const;
  float luminance() const;
  const float& operator[](int32_t) const;
  float& operator[](int32_t);
  mce::Color& operator*=(float);
  mce::Color& operator-=(const float);
  mce::Color& operator-=(const mce::Color&);
  mce::Color& operator+=(const mce::Color&);
  bool operator==(const mce::Color&) const;
  bool operator!=(const mce::Color&) const;
  bool operator<(const mce::Color&) const;
  mce::Color operator*(const mce::Color&) const;
  mce::Color operator*(float) const;
  mce::Color operator/(float) const;
  mce::Color darker(float) const;
  mce::Color brighter(float) const;
  mce::Color operator+(const mce::Color&) const;
  mce::Color operator-(const mce::Color&) const;
  void clamp();
  mce::Color clamped() const;
  bool isNil() const;
  bool isNan() const;
  bool operator bool() const;
  float distanceFrom(const mce::Color&) const;
  bool Serialize(Serializer&, SerializerTraits&);
  
  static mce::Color lerp(const mce::Color&, const mce::Color&, float);
  static mce::Color bilinear(const std::array<mce::Color,4>&, float, float);
  static mce::Color bilinear(const mce::Color&, const mce::Color&, const mce::Color&, const mce::Color&, float, float);
  static mce::Color fromHSB(float, float, float);
  static mce::Color fromABGR(int32_t);
  static mce::Color fromARGB(int32_t);
  static mce::Color fromRGB(int32_t);
  static float redFromARGB(int32_t);
  static float greenFromARGB(int32_t);
  static float blueFromARGB(int32_t);
  static mce::Color fromHexString(const std::basic_string<char,std::char_traits<char>,std::allocator<char> >&);
  static mce::Color fromBytes(const unsigned char*);
  static mce::Color fromIntensity(float, float);
};
