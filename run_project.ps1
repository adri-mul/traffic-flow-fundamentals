# For Windows operating system

# Write-Output "Configuring project"
# cmake -S . -B build

Write-Output "Running testing suite..."
# cmake --build build --target testproject

Write-Output "Running project..."
cmake --build build --target run
