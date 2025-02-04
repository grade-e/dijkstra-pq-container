FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    # libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN rm -rf build && mkdir build && cd build && cmake .. && make

# RUN cd build && ./test/dijkstra_test

CMD ["./build/dijkstra_main"]