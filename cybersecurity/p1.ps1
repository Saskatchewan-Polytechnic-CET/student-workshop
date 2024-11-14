# p0.ps1 prank payload
# Use files from the internet to:
# - Change wallpaper
# - Change USB disconnect sound

# Change wallpaper
#    Derived from https://gist.github.com/s7ephen/714023
$setwallpapersrc = @"
using System.Runtime.InteropServices;

public class Wallpaper
{
  public const int SetDesktopWallpaper = 20;
  public const int UpdateIniFile = 0x01;
  public const int SendWinIniChange = 0x02;
  [DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
  private static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);
  public static void SetWallpaper(string path)
  {
    SystemParametersInfo(SetDesktopWallpaper, 0, path, UpdateIniFile | SendWinIniChange);
  }
}
"@
Add-Type -TypeDefinition $setwallpapersrc

# Download a cat picture from the internet as cat.jpg
curl -o cat.jpg https://m.media-amazon.com/images/I/61hnicrIZ2L.jpg
# Set the desktop wallpaper as the new file downloaded
[Wallpaper]::SetWallpaper("./cat.jpg")

# Other possible sounds.
# Downloaded from https://www.myinstants.com
# - https://www.myinstants.com/media/sounds/spongebob-fail.mp3
# - https://www.myinstants.com/media/sounds/kooky-online-audio-converter.mp3

# Download sound from internet as save as wow.mp3
curl -o wow.mp3 https://www.myinstants.com/media/sounds/anime-wow-sound-effect-mp3cut.mp3
# Get the full path of the new file
$wowpath = Resolve-Path -Path "wow.mp3"
# Replace the USB disconnect sound with the new file downloaded
New-ItemProperty -Path HKCU:\AppEvents\Schemes\Apps\.Default\DeviceDisconnect\.Current -Name "(Default)" -Value "$wowpath" -Force | Out-Null
