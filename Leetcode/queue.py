from json.decoder import JSONDecodeError, JSONDecoder
import sys
import json

def delete(q, s):
    current_set = s
    for objS in s:
            PROP = False
            PROPVAL = False
            for valQ in q:
                if not PROP:
                    PROP = q.get(valQ) == objS.get(valQ)
                    if PROP: 
                        if len(q) == 1:
                            objS.clear()
                            remove_empty_elements(objS)
                            break
                try:
                    refS = objS.get(valQ)
                    refQ = q.get(valQ)
                    if isinstance(refQ, dict):
                        for subVal in refQ:
                            if not PROPVAL:
                                PROPVAL = refQ.get(subVal) == refS.get(subVal)
                    elif isinstance(refS, list):
                        for subVal in refQ:
                            if not PROPVAL:
                                PROPVAL = subVal in refS  
                except KeyError:
                    print("Not able to Delete, Location Not Found")
                    continue
                if PROP and PROPVAL: 
                    objS.clear()
                    remove_empty_elements(objS)
                    break
    return current_set

def remove_empty_elements(d):
    """recursively remove empty lists, empty dicts, or None elements from a dictionary"""

    def empty(x):
        return x is None or x == {} or x == []

    if not isinstance(d, (dict, list)):
        return d
    elif isinstance(d, list):
        return [v for v in (remove_empty_elements(v) for v in d) if not empty(v)]
    else:
        return {k: v for k, v in ((k, remove_empty_elements(v)) for k, v in d.items()) if not empty(v)}



def get(q, s):
    ans_set = s
    for dicObj in ans_set:
        update = []
        p = False
        pv = False
        for subObj in dicObj:
            try:
                s_child = dicObj[subObj]
                q_child = q[subObj]
                if isinstance(q_child, dict):
                    for val in q_child:
                        if q_child[val] == s_child[val]:
                            pv = True
                            update.append(dicObj) 
                    break             
                elif q_child == s_child:
                    p = True
                    update.append(dicObj)
            except:
                continue
            task = (p and pv)
            if task: 
                ans_set = update
        
    return ans_set

def getValues(q, s):
    new_set = []
    for objS in s:
        PROP = False
        PROPVAL = False
        for valQ in q:
            if not PROP:
                PROP = q.get(valQ) == objS.get(valQ)
                if PROP: 
                    if len(q) == 1:
                        new_set.append(objS)
                        break
            try:
                refS = objS.get(valQ)
                refQ = q.get(valQ)
                if isinstance(refS, dict):
                    for subVal in refQ:
                        if not PROPVAL:
                            PROPVAL = refQ.get(subVal) == refS.get(subVal)
                elif isinstance(refS, list):
                    for subVal in refQ:
                        if not PROPVAL:
                            PROPVAL = subVal in refS  
            except KeyError:
                print("Not able to find Match, Location Deleted")
                continue
            if PROP and PROPVAL: 
                new_set.append(objS)
                break
    return new_set


def main():
    updated_json = []
    for line in sys.stdin:
        if line[0:3] == 'add':
            json_data = line[4:]
            parsed_json = (json.loads(json_data))
            try:
                updated_json.append(parsed_json)
            except json.decoder.JSONDecodeError as e:
	            print("Not able to Add, the string could not be converted to JSON", e)

        if line[0:3] == 'get':
            json_data = line[4:]
            parsed_json = (json.loads(json_data))
            
            try:
                located_objects = getValues(parsed_json, updated_json)
                for every in located_objects:
                    print(every, end='\n')
            except KeyError:
                print("Not able to find Match")

        if line[0:6] == 'delete':
            json_data = line[7:]
            parsed_json = (json.loads(json_data))
            try:
                updated_json = delete(parsed_json, updated_json)
                for every in updated_json:
                    print(every, end='\n')
            except KeyError:
                print("Not able to Remove")

        if 'q' == line.rstrip():
            break

if __name__ == '__main__':
    main()
