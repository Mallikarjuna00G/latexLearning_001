# Learning drawing from `Tikz & PGF Package` manual

- Source: [https://www.ctan.org/pkg/pgf](https://www.ctan.org/pkg/pgf)

## Chapter 1: Introduction
[ch01](./ch01/)
- drawing001: https://youtube.com/shorts/BjHjJE5-uGA?feature=share

## Chapter 2: Tutorial: A Picture for Karl’s Students
[ch02](./ch02/)
- ch2p2p1: https://youtube.com/shorts/43q4jPSy6gk?feature=share
- ch2p3: https://youtube.com/shorts/YSTW86RrG_I?feature=share
- ch2p4_001: https://youtube.com/shorts/WIpmJ0Lnn3s?feature=share
- ch2p4_002: https://youtube.com/shorts/prKiJGzjTSU?feature=share
- ch2p5_001: https://youtube.com/shorts/6y2Z7u4lCqQ?feature=share
- ch2p5_002: https://youtube.com/shorts/Dl5RUACctAI?feature=share
- ch2p6_001: https://youtube.com/shorts/H1ANHAkglN0?feature=share
- ch2p7_001: https://youtube.com/shorts/GtFKUnCa814?feature=share
- ch2p8_001: https://youtube.com/shorts/lBnQ7TlLF9E?feature=share
- ch2p8_002: https://youtube.com/shorts/mPJ5E7o0YrY?feature=share
- ch2p10_001: https://youtube.com/shorts/cqjfJFABo64?feature=share
- ch2p10_002: https://youtube.com/shorts/u5P1EnaICuc?feature=share
- ch2p11_001: https://youtube.com/shorts/Qu4bgCbi0A8?feature=share
- ch2p12_001: https://youtube.com/shorts/9q_awHiHlEo?feature=share
- ch2p12_002: https://youtube.com/shorts/IdF9sMDu-7c?feature=share
- ch2p12_003: https://youtube.com/shorts/rNIr8uEpBTg?feature=share
- ch2p13_001: https://youtube.com/shorts/7GHlzeHjVWQ?feature=share
- ch2p13_002: https://youtube.com/shorts/UsEC4_-AgU4?feature=share
- ch2p13_003: https://youtube.com/shorts/liFeF6SOTU0?feature=share
- ch2p13_003_1: https://youtube.com/shorts/aseUEj-Hjck?feature=share
- ch2p14_001: https://youtube.com/shorts/_4QCGndqv4A?feature=share
- ch2p14_002: https://youtube.com/shorts/fExzrikAqlM?feature=share
- ch2p14_003: https://youtube.com/shorts/hvNEFLVjkEk?feature=share
- ch2p15_001: https://youtube.com/shorts/cDog1blN9UM?feature=share
- ch2p15_002: https://youtube.com/shorts/QLDjvUvVNGk?feature=share
- ch2p15_003: https://youtube.com/shorts/YnMgwWhP7N8?feature=share
- ch2p15_004: https://youtube.com/shorts/73vxQSh_RV8?feature=share
- ch2p15_005: https://youtube.com/shorts/lKjB8__JkjA?feature=share
- ch2p16_001: https://youtube.com/shorts/FfdgtPsoFM8?feature=share
- ch2p17_001: https://youtube.com/shorts/9_TMfVhA_Bk?feature=share
- ch2p17_002: https://youtube.com/shorts/5b7TqqfkGY0?feature=share
- ch2p17_003: https://youtube.com/shorts/E692iIoHNxI?feature=share
- ch2p18_001: https://youtube.com/shorts/KbaDTuALW5s?feature=share
- ch2p19_001: https://youtube.com/shorts/MOci5DcTjdg?feature=share
- ch2p19_002: https://youtube.com/shorts/FdfGdGdTpxU?feature=share
- ch2p20_001: https://youtube.com/shorts/YFgTinmfoqc?feature=share
- ch2p20_002: https://youtube.com/shorts/6ta1ResgIes?feature=share
- ch2p20_003: https://youtube.com/shorts/wF7p-uoe4Zk?feature=share
- ch2p20_004: https://youtube.com/shorts/gq2u7vBB6QE?feature=share
- ch2p20_005: https://youtube.com/shorts/j6d2Jehqyg0?feature=share
- ch2p20_006: https://youtube.com/shorts/OeVA8SZUnqc?feature=share
- ch2p21_001: https://youtube.com/shorts/XDw7_ht9mG0?feature=share
- ch2p21_002: https://youtube.com/shorts/H0zoh-yYaZw?feature=share
- ch2p21_003: https://youtube.com/shorts/5VlvcvvZEsM?feature=share
- ch2p21_004: https://youtube.com/shorts/HsIe3S7uf54?feature=share
- ch2p21_005: https://youtube.com/shorts/JdI8rkvEWEM?feature=share
- ch2p21_006:
    - Part1: https://youtube.com/shorts/T2pPHCqS-j0?feature=share
    - Part2: https://youtube.com/shorts/IYA-Vl0pCRQ?feature=share
    - Part3: https://youtube.com/shorts/M_P9P-e3dcc?feature=share
- ch2p22_001: https://youtube.com/shorts/AZgcQzSFQiY?feature=share

## Chapter 3: Tutorial: A Petri-Net for Hagen

[ch03](./ch03/)

- ch3p2p1_001: https://youtube.com/shorts/tng2vnCjoi8?feature=share
- ch3p3_001: https://youtube.com/shorts/AvZ_Mo6uB0M?feature=share
- ch3p4_001: https://youtube.com/shorts/0-s_EREjYrM?feature=share
- ch3p4_002: https://youtube.com/shorts/TTqfYwywIcQ?feature=share


| LaTeX | TikZ & PGF | #latex #tikz #pgf

Playlist TikzPgf_Set1: https://www.youtube.com/playlist?list=PLrc97KaHTPpsLnX8gIxdofCyHpQT3EYP3

latex,tikz,pgf,latex-graphics


## Youtube API handling setup

Place the `client_secrets.json` in the same directory of the C++ source files. **But definitely do not share/git track** this file.

```console
sudo apt install libcurl4-openssl-dev nlohmann-json3-dev
```

We have [get_refresh_token.cpp](./get_refresh_token.cpp) for getting the refresh token.

Compilation command:

```console
g++ -std=c++17 get_refresh_token.cpp -lcurl -o get_token.out
```

Running command:

```console
./get_token.out
```

This will open the browser for authentication. After authentication, it will print the refresh token.

Copy that outputted token safely. Or may add the refresh token as a key-value pair to `client_secrets.json` giving key name as `refresh_token`.


And we have [uploader.cpp](./uploader.cpp) for uploading the video to youtube.

Compilation command:

```console
g++ -O3 -std=c++17 uploader.cpp -lcurl -o yt_upload.out
```

Execution command:

```console
./yt_upload.out <video_path>
```

Eg: 
```console
./yt_upload.out build/output_render.mp4
```


### Compilation via CMake

Alternatively, you can build both tools using CMake:

1. Create and navigate to a build directory inside `tikzPgf_manual`:
   ```console
   mkdir -p build && cd build
   ```

2. Generate the build files:
   ```console
   cmake ..
   ```
   *Note: To build in Release mode (which compiles the uploader with optimization flags), use `cmake -DCMAKE_BUILD_TYPE=Release ..`.*

3. Build the default uploader target:
   ```console
   cmake --build .
   ```
   This generates the executable `./yt_upload.out` in the build directory.

4. Build the non-default token retriever target:
   ```console
   cmake --build . --target get_refresh_token
   ```
   This generates the executable `./get_token.out` in the build directory.

### Running the Compiled Binaries

Once compiled, you can launch the binaries directly from your build folder, passing arguments exactly as before:

- **Retrieve refresh token**:
  ```console
  ./get_token.out
  ```

- **Upload a video**:
  ```console
  ./yt_upload.out <path_to_video.mp4>
  ```