/*******************************************************************************************
htons(): reorder the bytes of a 16-bit unsigned value from processor order to network order.
         The macro name can be read "host to network short." 
htonl(): reorder the bytes of a 32-bit unsigned value from processor order to network order.
         The macro name can be read "host to network long." 
ntohs(): reorder the bytes of a 16-bit unsigned value from network order to processor order.
         The macro name can be read "network to host short." 
ntohl(): reorder the bytes of a 32-bit unsigned value from network order to processor order.
         The macro name can be read "network to host long." 
********************************************************************************************/


#if defined(BIG_ENDIAN) && !defined(LITTLE_ENDIAN)

#define htons(A)  (A)
#define htonl(A)  (A)
#define ntohs(A)  (A)
#define ntohl(A)  (A)

#elif defined(LITTLE_ENDIAN) && !defined(BIG_ENDIAN)

#define htons(A)  ((((uint16)(A) & 0xff00) >> 8) | \
                   (((uint16)(A) & 0x00ff) << 8))
#define htonl(A)  ((((uint32)(A) & 0xff000000) >> 24) | \
                   (((uint32)(A) & 0x00ff0000) >> 8)  | \
                   (((uint32)(A) & 0x0000ff00) << 8)  | \
                   (((uint32)(A) & 0x000000ff) << 24))
#define ntohs     htons
#define ntohl     htohl

#else

#error "Either BIG_ENDIAN or LITTLE_ENDIAN must be #defined, but not both."

#endif
