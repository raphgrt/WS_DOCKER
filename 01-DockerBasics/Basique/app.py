import platform
import os
import sys

def detect_os():
    """Détecte et affiche des informations sur le système d'exploitation."""
    
    os_name = platform.system()
    os_version = platform.version()
    os_release = platform.release()
    os_architecture = platform.architecture()
    machine_type = platform.machine()
    python_version = sys.version
    
    print("=== Informations sur le système d'exploitation ===")
    print(f"Système: {os_name}")
    
    # Informations spécifiques selon le système
    if os_name == "Darwin":
        print(f"Type: macOS")
        print(f"Version macOS: {platform.mac_ver()[0]}")
    elif os_name == "Linux":
        try:
            # Tentative de lecture du fichier os-release pour les distributions Linux
            with open('/etc/os-release', 'r') as f:
                lines = f.readlines()
            os_info = {}
            for line in lines:
                if '=' in line:
                    k, v = line.strip().split('=', 1)
                    os_info[k] = v.strip('"')
            print(f"Distribution: {os_info.get('PRETTY_NAME', 'Inconnu')}")
        except:
            print("Distribution Linux: Informations détaillées non disponibles")
    elif os_name == "Windows":
        try:
            win_version = platform.win32_ver()
            print(f"Version Windows: {win_version[0]} {win_version[1]}")
        except:
            print(f"Version Windows: {os_release}")
    
    print(f"Version: {os_version}")
    print(f"Release: {os_release}")
    print(f"Architecture: {os_architecture[0]}, {os_architecture[1]}")
    print(f"Type de machine: {machine_type}")
    print(f"Version de Python: {python_version.split()[0]}")
    
    return os_name

if __name__ == "__main__":
    detect_os()
