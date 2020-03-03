/*
* Copyright 2020 https://glumes.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

#ifdef PROJECT_DIR_PATH
string image_path = string(PROJECT_DIR_PATH) + "/resource/image/image-jpg-640x426.jpg";
#endif

const int width = 640, height = 426;

int main() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return -1;
    }

    SDL_Window *pWindow = SDL_CreateWindow("Hello SDL",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           width, height,
                                           SDL_WINDOW_ALLOW_HIGHDPI);


    SDL_Surface *pWindowSurface = SDL_GetWindowSurface(pWindow);
    SDL_Surface *pImageSurface = IMG_Load(image_path.c_str());

    bool bQuit = false;
    SDL_Event windowEvent;
    while (!bQuit){
        while (SDL_PollEvent(&windowEvent)){
            switch (windowEvent.type){
                case SDL_QUIT:
                    bQuit = true;
                    break;
                default:
                    break;
            }
        }
        SDL_BlitSurface(pImageSurface, nullptr,pWindowSurface,nullptr);
        SDL_UpdateWindowSurface(pWindow);
    }

    pWindowSurface = nullptr;
    pImageSurface = nullptr;
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}