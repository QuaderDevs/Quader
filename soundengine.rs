// quader.vanished.lol | Licenced under the MIT licence, (c) 2024 Chlove
use std::error::Error;
use std::process;
use rodio::Source;
use std::fs::File;
use std::io::BufReader;

fn main() {
    // Path to your audio file
    let audio_file_path = "audio.wav";

    // Attempt to load and play the audio file
    match play_audio_file(audio_file_path) {
        Ok(_) => println!("Audio playback completed."),
        Err(e) => {
            eprintln!("Error: {}", e);
            process::exit(1);
        }
    }
}

fn play_audio_file(audio_file_path: &str) -> Result<(), Box<dyn Error>> {
    // Open the file at the provided path
    let file = File::open(audio_file_path)?;
    let source = rodio::Decoder::new(BufReader::new(file))?;

    // Initialize the audio device and play the audio
    let device = rodio::default_output_device().ok_or("No output device available.")?;
    rodio::play_raw(&device, source.convert_samples());

    Ok(())
}
