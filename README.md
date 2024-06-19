# FroggyPowerServer
---

This is just a begining. Took me ages to configure, and for some reason Mason
cannot find the Arduino files so it's going to hard to write code...
Anyways if you want to keep on going with me you will need a Relay Module.
We will need it to turn on the main server.

---

## Build

This should work for now (I automated the compilation and uplaoding so make sure
CMakeLists.txt builds for your board)
```
cmake -S. -Bbuild
cd build
make
```

