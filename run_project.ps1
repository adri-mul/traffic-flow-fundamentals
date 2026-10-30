# For Windows operating system

# Write-Output "Configuring project"
#cmake -S . -B build

# Copy data files to build directory
Copy-Item -Path "data\*" -Destination "build\data" -Recurse -Force

Write-Output "Running testing suite..."
# cmake --build build --target testproject

Write-Output "Running project..."
cmake --build build --target run
