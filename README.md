# msgpass
```
sudo docker build --no-cache -t nlohmann .

sudo docker run --name nloh_container -v $(pwd):/work --rm -it nlohmann

cmake -Bbuild -S. && cmake --build build 

This is a async tcp client yet to be done!
{"data":{"age":101,"name":"json"},"id":"e42a5423-db32-425b-9f77-5727f55393e8","pattern":"some_pattern"}#
connect: Connection refused [system:111 at /home/leanne/wpre/msgpass/build/_deps/boost-src/libs/asio/include/boost/asio/detail/reactive_socket_service.hpp:587 in function 'connect']
```