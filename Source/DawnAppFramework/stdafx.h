#pragma once

#include "targetver.h"

#include <WinSock2.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <sstream>
#include <thread>
#include <mutex>
#include <map>
#include <locale>
#include <codecvt>

#include <openssl/rsa.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/engine.h>

#include "DACore.h"
#include "DACrypt.h"
#include "libDN.h"

#pragma comment (lib, "DACore.lib")
#pragma comment (lib, "DANetwork.lib")
#pragma comment (lib, "DACrypt.lib")
#pragma comment (lib, "DNService.lib")

