#ifndef BASE64_H
#define BASE64_H
#include <string>
using namespace std;

 /* base 64 */
extern int	b64_encode(const char *src, int len, char *dst);
extern int	b64_decode(const char *src, int len, char *dst);
extern int	b64_enc_len(int srclen);
extern int	b64_dec_len(int srclen);

#endif
