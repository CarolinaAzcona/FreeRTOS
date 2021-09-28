#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWTCCAkGgAwIBAgIUEKzpqmpE/mAuf2ihs/A+4wyb0UIwDQYJKoZIhvcNAQEL\n"\
"BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n"\
"SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIxMDkyNDExNTQy\n"\
"MVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n"\
"ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMK014ShiLrPFmhhnPsP\n"\
"f5VLGlrZc4bUmTOooBwwil4P9uYqhI9PWAIeyo99Q8U8HZ/wo5ERGtGGMP/bPx6F\n"\
"mqKx3p9QJyXuzM4gpOj+vaJmWqPyhlUIx4Se5zPNFD5GAiuWpHj1wGCjtlNg+Hpu\n"\
"gVpS7YgIVW4OjLxrVF8f5hrxGvbzULKHJoR/FP8DR/bE2FtDXrhNtbJzl0fkPkQ+\n"\
"VcBKn+QMF/+1Rr8Nd4SUX4hRaeOcpL/M/Dvm/KIaTgHtXAvMjyPO1RAzrbzLog5Q\n"\
"80TWpPfo7gIuKVIRb1sBNXqDFjcAoIkadBT6Or7U9pZAXs/OME8I5EtIE0rZjE+r\n"\
"brUCAwEAAaNgMF4wHwYDVR0jBBgwFoAUWBt1eBKwgE9BQwdZsY6T2/l6FBwwHQYD\n"\
"VR0OBBYEFLjyCIEzPMq2SS5+g6euNF8cW+jiMAwGA1UdEwEB/wQCMAAwDgYDVR0P\n"\
"AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQB0iggC7InYvvd62ZPKskLq+twG\n"\
"V8v24T+3okolqe4JQD4EmdN/6HqlWeG6RVYiyYKl4n8ZlXW/uzW0MgnPlS6VRpsb\n"\
"uJ+36M46xrh4CoMeEWfT2X46f8ZW9AGE/sPu7KXgmbqIcKaIG6TyXxryJZQsEZSK\n"\
"EmGXZ1m5DQ514pk04zW4X6OeItE0nfw3NgsqKXQ5g7ZKv3TS/M83/m+cEuxX2eIl\n"\
"8/3B/EIZTFV/h6p7kc5Yz7M6pmJUUpscQgR46pzvdYJgiXqsTDuuZV/7lD9ho0XL\n"\
"6QOFnB36sq5SZfxxWp78sdJ2ttDEcKL94WgEoLymQsGtMkgmHExuGga74aEp\n"\
"-----END CERTIFICATE-----"

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEowIBAAKCAQEAwrTXhKGIus8WaGGc+w9/lUsaWtlzhtSZM6igHDCKXg/25iqE\n"\
"j09YAh7Kj31DxTwdn/CjkREa0YYw/9s/HoWaorHen1AnJe7MziCk6P69omZao/KG\n"\
"VQjHhJ7nM80UPkYCK5akePXAYKO2U2D4em6BWlLtiAhVbg6MvGtUXx/mGvEa9vNQ\n"\
"socmhH8U/wNH9sTYW0NeuE21snOXR+Q+RD5VwEqf5AwX/7VGvw13hJRfiFFp45yk\n"\
"v8z8O+b8ohpOAe1cC8yPI87VEDOtvMuiDlDzRNak9+juAi4pUhFvWwE1eoMWNwCg\n"\
"iRp0FPo6vtT2lkBez84wTwjkS0gTStmMT6tutQIDAQABAoIBACALZ1T6yOgF4Sg4\n"\
"uH9RY6wMej/tfef44WXxILjC/GLSuc3TvZFge5mNu8S11wuFA1MpZaIgcIt/TF0v\n"\
"lknNr0+Lepo5tNe3X5mlIb7+/fLWaaCF77nbAgs/o8mQvP4qw3ytBFCsEYdWKlG6\n"\
"qepseXmGIHW8+WJtnpf8ChzFwTc5oXRPuBATp2fIlejESMqcsOMJGARx6lG98Pk1\n"\
"guHfv8dk+2IBf8XmXCwk9mvChr7y6G1TukSPvhl6tVcVP2LWMAyd0g0+aO9QV0j3\n"\
"U+FuC8RKG7TZ9LBSHCFHaJ4PAQBICEUwd9mQ8seA/Y1c9Yj6AUlYMDP+L8iYIR4P\n"\
"pq8OtIECgYEA84YaHK+L3c2UV+Rth059wWgFJDjissOL9veN2XS37XzTnbHeYRrR\n"\
"+hL+bE7p0Z19PbfJSEYonOOanVY9uKfKD4YZqNgJh8tK5ZpO2bJnAikabXjU9wba\n"\
"j+whhPZm3u+LG9pVLc6PrVQ/BI33OTRVu2v62MLyYu6ixZfSYyREvBECgYEAzK57\n"\
"leW/V9KvvflB1oTs9UDzQAPboxoAGmyR6uzMYn4eUXIZKmZ5lZ6xa+8nAYRBsr10\n"\
"6Fv5R1gW2vU3hdPn5O0Ks4bDfmf1ZPDqUiS1jiCsyhrtMY1GTBX2hChTiWYn3G10\n"\
"yWf5g2I54ZfERm1Fxbm1lvYf0IWEvyVEeRclfGUCgYAWgMXY8L/T9zNGC+2zGyWz\n"\
"wZD4D+mi6z77y1RoS8jTQT2szMrn3jqZCThJeeFRZWQ1V85Zx2HpXX7kGxwI/DhH\n"\
"xvSIDa6Txc1d+ixfIYUzRekTRJ8pVJDNy9wtFTfcUfZg1IQaf4P3WFmaaiP2PUfO\n"\
"0eOUNC+BxNt1ttnSH3/agQKBgFPhpdA2iYYKV+94+Rxa+WlBJu8zJY3gF+68U8h9\n"\
"Jv2uReqG4f1YZbeFg5yCM/ARLYN81S5skupEFYnCOPDleQF+i4YrUm65V/34JW9o\n"\
"j+chSO7CvjYyeX6w+YgLpsCGVwuk59mqfLz1QldLhSp/mbqAcwTc9QjVzyMuuLMP\n"\
"Y1NpAoGBANec9GoqjTMQppXczzKmRnNgpFXwzECHx3ifBkIk5KQY0d1v7bQJRCD9\n"\
"GhJzmSCB7KiulWHtFx0WoSCbgBZn9LreiJ3e30ApoclhPDtjvn/k5FriIfeUae8B\n"\
"KOhLSsSReZSeIMJ03C3ht7eq2FDgCDOvAnV25q9Ipdb2O1c6SkWX\n"\
"-----END RSA PRIVATE KEY-----"

/*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  ""


#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
