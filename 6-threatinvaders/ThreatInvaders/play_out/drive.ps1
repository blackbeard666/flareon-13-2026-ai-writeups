
Add-Type -AssemblyName System.Windows.Forms,Microsoft.VisualBasic
Start-Sleep -Milliseconds 500
[Microsoft.VisualBasic.Interaction]::AppActivate("ThreatInvaders")
Start-Sleep -Milliseconds 400
function K($k){ [System.Windows.Forms.SendKeys]::SendWait($k); Start-Sleep -Milliseconds 120 }
# F1 open debug injector, submit a couple injected scores
K("{F1}"); Start-Sleep -Milliseconds 300
K("{ENTER}"); Start-Sleep -Milliseconds 400
K("{F6}"); Start-Sleep -Milliseconds 500   # burst x10 if available
K("{ENTER}"); Start-Sleep -Milliseconds 400
# also try normal play: back to title then play
K("{ESC}"); Start-Sleep -Milliseconds 300
K(" "); Start-Sleep -Milliseconds 300      # start game
1..40 | ForEach-Object { [System.Windows.Forms.SendKeys]::SendWait(" "); [System.Windows.Forms.SendKeys]::SendWait("{LEFT}"); [System.Windows.Forms.SendKeys]::SendWait("{RIGHT}"); Start-Sleep -Milliseconds 150 }
Start-Sleep -Seconds 3
# name/comment entry submit
K("F"); K("L"); K("A"); K("G"); K("{ENTER}"); Start-Sleep -Milliseconds 300
K("h"); K("i"); K("{ENTER}"); Start-Sleep -Milliseconds 300
