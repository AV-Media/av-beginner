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
#include <SDL.h>
using namespace std;

#define SDL_CUSTOM_EVENT  (SDL_USEREVENT + 1)

int sdl_thread_custom_event(void *){

    SDL_Delay(5000);

    SDL_Event sdlEvent;

    sdlEvent.type = SDL_CUSTOM_EVENT;
    SDL_PushEvent(&sdlEvent);
    return 0;
}

int main() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return -1;
    }

    int width = 400;
    int height = 400;
    SDL_Window *window = SDL_CreateWindow("Hello SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,height,
                                          SDL_WINDOW_ALLOW_HIGHDPI);


    SDL_Renderer* pRenderer = NULL;
    // 创建渲染器
    pRenderer = SDL_CreateRenderer(window, -1, 0);
    // 指定渲染颜色
    SDL_SetRenderDrawColor(pRenderer,0,255,0,255);
    // 清空当前窗口的颜色
    SDL_RenderClear(pRenderer);
    // 执行渲染操作，更新窗口
    SDL_RenderPresent(pRenderer);

    SDL_Event windowEvent;

//    while (true){
//        if (SDL_PollEvent(&windowEvent)){
//            if (SDL_QUIT == windowEvent.type){
//                break;
//            }
//        }
//    }

    SDL_CreateThread(sdl_thread_custom_event, "custom_event", nullptr);


    bool bQuit = false;
    while (!bQuit){
        while (SDL_PollEvent(&windowEvent)){
            switch (windowEvent.type){
                case SDL_QUIT:
                    bQuit = true;
                    break;
                case SDL_KEYDOWN:
                    if (windowEvent.key.keysym.sym == SDLK_SPACE){
                        cout << "user click space \n" ;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("button index  is %d\n",windowEvent.button.button);
                    break;
                case SDL_CUSTOM_EVENT:
                    cout << "receive user custom event\n";
                    break;
                default:
                    break;
            }
        }
    }

//    通过 SDL_WaitEvent 来监听事件
//    bool bQuit = false;
//    while (!bQuit){
//        SDL_WaitEvent(&windowEvent);
//        if (windowEvent.type == SDL_QUIT){
//            bQuit = true;
//            break;
//        } else{
//            cout << "get event" << endl;
//        }
//    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(pRenderer);
    SDL_Quit();

    return 0;
}