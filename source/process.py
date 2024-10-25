import multiprocessing
import subprocess

def run_main_exe(process_id):
    arg = str(process_id)
    subprocess.run(["main.exe", arg])

if __name__ == "__main__":
    processes = []

    for i in range(0, 2):
        process = multiprocessing.Process(target=run_main_exe, args=(i ,))
        processes.append(process)
        process.start()

    # Đợi tất cả các tiến trình con kết thúc
    for process in processes:
        process.join()