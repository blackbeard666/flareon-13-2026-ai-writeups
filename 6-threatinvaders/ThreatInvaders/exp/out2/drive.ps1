
Add-Type -AssemblyName System.Windows.Forms,Microsoft.VisualBasic
function K($k){ [System.Windows.Forms.SendKeys]::SendWait($k); Start-Sleep -Milliseconds 150 }
for($r=0; $r -lt 3; $r++){
  try { [Microsoft.VisualBasic.Interaction]::AppActivate("ThreatInvaders") } catch {}
  Start-Sleep -Milliseconds 400
  K("{ESC}")            # ensure title
  Start-Sleep -Milliseconds 200
  K("f")                # feedback screen
  Start-Sleep -Milliseconds 300
  foreach($ch in @("Q","W","E","R","T","Y","1","2","3","4","5","6","7","8","9","0")){ K($ch) }
  K("{ENTER}")          # submit feedback
  Start-Sleep -Seconds 8
}
