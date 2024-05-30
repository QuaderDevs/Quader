// quader.vanished.lol | Licenced under the MIT licence, (c) 2024 Chlove
using System;
using System.Media;

namespace AudioPlayer
{
    class Program
    {
        static void Main(string[] args)
        {
            // Path to your audio file
            string audioFilePath = @"audio.wav";

            // Create a new SoundPlayer instance
            SoundPlayer player = new SoundPlayer(audioFilePath);

            try
            {
                // Load the .wav file
                player.Load();

                // Play the .wav file
                player.PlaySync(); // PlaySync plays the sound synchronously
                // You can use Play() to play asynchronously or PlayLooping() to loop playback
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }
    }
}

