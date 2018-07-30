#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Design a musical jukebox using object-oriented principles.
 *
 * Functions:
 * - Choose a song
 *   - Scroll/flip through song listing
 * - Enter money
 * - Queue up song to play
 */

class Song
{
  public:
    /**
     * blocks until song is finished playing
     */
    void play();

    std::string name, artist, album;
    void *data;
};
typedef std::map<std::string,Song> Songs;

class JukeBox 
{
  public:

    /**
     * queue up song to play next
     * @return 0 on success, 1 if not enough credits, -1 on error
     */
    int queueSong(const Song &song);

    const Songs &getSongListing() const;

    /**
     *
     */
    bool enterCredits(int amount, int &change);

  private:
    class SongPlayer
    {
      public:
        SongPlayer(std::queue<Song> &songQ);

        run();

      private:
        std::queue<Song> &songQ_;
    };

    std::queue<Song> songQ_;
};

int main(int argc, const char *argv[])
{

  
  return 0;
}
