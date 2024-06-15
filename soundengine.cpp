#include <iostream>
#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void playAudioFile(const std::string& audioFilePath) {
    // Initialize SDL with audio subsystem
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
    }

    // Load WAV file
    Mix_Chunk* chunk = Mix_LoadWAV(audioFilePath.c_str());
    if (!chunk) {
        throw std::runtime_error("Error loading audio file: " + std::string(Mix_GetError()));
    }

    // Open audio device
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) < 0) {
        throw std::runtime_error("SDL mixer audio device initialization failed: " + std::string(Mix_GetError()));
    }

    // Play audio
    Mix_PlayChannel(-1, chunk, 0);

    // Wait until audio finishes
    SDL_Delay(chunk->alen * 1000 / (chunk->freq * chunk->channels));

    // Cleanup
    Mix_FreeChunk(chunk);
    Mix_CloseAudio();
    SDL_Quit();
}

int main() {
    // Path to your audio file
    std::string audioFilePath = "audio.wav";

    try {
        // Attempt to load and play the audio file
        playAudioFile(audioFilePath);
        std::cout << "Audio playback completed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
