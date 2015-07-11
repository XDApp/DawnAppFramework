#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>


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

#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/engine.h>

#include "DACore.h"

#pragma comment(lib, "libeay32.lib")
#pragma comment(lib, "ssleay32.lib")
