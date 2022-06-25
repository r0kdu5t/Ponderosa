
Spotify desk application installation. Reference this: https://linuxhint.com/installing_spotify_linux_mint/

Not using snap but using deb.

Maybe I'll list steps here or drop some cli bits later.
step 1.
echo deb http://repository.spotify.com stable non-free | sudo tee /etc/apt/sources.list.d/spotify.list
  Note there was an error in the preceeding line - no space after the FQDN before package. Have added space in these notes.

Step 2.
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 4773BD5E130D1D45
  Not sure but got an error about 'Permission denied' from previous command, so prefixed it with 'sudo'
  Then it returned with no errors.
  
Step 3.
sudo apt install spotify-client
  Aside from the previously identified error(s) when corrected was able to finish install.
  
Step 4.
  Confirmed with the following.
spotify --version

-- Andrew 25 - June 2022
