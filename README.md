# msgpass
```
sudo docker build --no-cache -t nlohmann .

sudo docker run --name nloh_container -v $(pwd):/work --rm -it nlohmann

cmake -Bbuild -S. && cmake --build build 
```